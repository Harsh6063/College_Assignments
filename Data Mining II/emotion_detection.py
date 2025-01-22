import pandas as pd
import nltk
from nltk.corpus import stopwords
from nltk.stem import WordNetLemmatizer
import string
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.cluster import KMeans, AgglomerativeClustering, DBSCAN
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import BaggingClassifier,VotingClassifier
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.metrics import classification_report

emotion_df=pd.read_csv("emotional_dataset.csv") 
# Initialize lemmatizer and stop words
lemmatizer = WordNetLemmatizer()
stop_words = set(stopwords.words('english'))

def preprocess_text(text):
    # Tokenization
    tokens = nltk.word_tokenize(text.lower())
    
    # Remove punctuation and stop words, and lemmatize
    tokens = [lemmatizer.lemmatize(word) for word in tokens if word not in stop_words and word not in string.punctuation]
    
    return ' '.join(tokens)

# Apply preprocessing
emotion_df['processed_text'] = emotion_df['Text'].apply(preprocess_text)


new_emotion=emotion_df.drop(columns=['Text'])


from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.ensemble import BaggingClassifier
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report
import joblib

# Prepare features and labels
X = emotion_df['processed_text']
y = emotion_df['Emotion']

# Split the dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Vectorization with n-grams and limited features
vectorizer = TfidfVectorizer(max_features=5000, ngram_range=(1, 2))
X_train_vectorized = vectorizer.fit_transform(X_train)
X_test_vectorized = vectorizer.transform(X_test)

# Grid search for best SVM parameters
param_grid_svm = {
    'C': [0.1, 1, 10],
    'kernel': ['linear', 'rbf'],
    'gamma': [0.1, 0.01, 0.001]
}

grid_search_svm = GridSearchCV(SVC(probability=True), param_grid_svm, cv=3, scoring='accuracy')
grid_search_svm.fit(X_train_vectorized, y_train)
best_svm = grid_search_svm.best_estimator_

# Bagging classifier with optimized SVM and increased estimators
bagging = BaggingClassifier(estimator=best_svm, n_estimators=30, random_state=42)
bagging.fit(X_train_vectorized, y_train)

# Make predictions and evaluate the model
y_pred = bagging.predict(X_test_vectorized)
print(classification_report(y_test, y_pred))

# Save the model and vectorizer
joblib.dump(bagging, 'emotion_model.pkl')
joblib.dump(vectorizer, 'vectorizer.pkl')

import streamlit as st
import joblib
import numpy as np

# Load your trained model and vectorizer
class EmotionModel:
    def __init__(self):
        self.model = joblib.load('emotion_model.pkl')
        self.vectorizer = joblib.load('vectorizer.pkl')
        self.sentiment_mapping = {
            'joy': 'Positive',
            'love': 'Positive',
            'anticipation': 'Positive',
            'optimism': 'Positive',
            'calm': 'Positive',
            'trust': 'Positive',
            'fear': 'Negative',
            'disgust': 'Negative',
            'anger': 'Negative',
            'frustration': 'Negative',
            'confusion': 'Negative',
            'sadness': 'Negative',
            'neutral': 'Neutral',
            'surprise': 'Neutral',
            # Add more emotions and their corresponding sentiments as needed
        }

    def predict(self, text):
        text_vectorized = self.vectorizer.transform([text])
        return self.model.predict(text_vectorized)[0], self.model.predict_proba(text_vectorized)[0]

    def get_sentiment(self, emotion):
        return self.sentiment_mapping.get(emotion, "Unknown")

# Initialize the model outside of the function for better performance
model = EmotionModel()

# Title section with project name
st.markdown("<h1 style='text-align: center; color: #FFC107;'>Data Mining II Project</h1>", unsafe_allow_html=True)
st.title("🤖 Emotion Detection in Text")
st.markdown("<h4 style='font-size: 22px;'>Enter a sentence below and click 'Predict' to see the predicted emotion.</h4>", unsafe_allow_html=True)


# Team members section with enhanced styling
st.sidebar.markdown("<h2 style='font-size: 28px; color: #FF5722;'>Team Members</h2>", unsafe_allow_html=True)

# Team members list with better formatting
team_members = """
<ul style='list-style-type: none; padding: 0;'>
    <li style='font-size: 20px; margin: 10px 0;'><strong>Harsh Arora</strong> (AE-1218)</li>
    <li style='font-size: 20px; margin: 10px 0;'><strong>Harshita Singh</strong> (AE-1221)</li>
    <li style='font-size: 20px; margin: 10px 0;'><strong>Hardik Bhaniya</strong> (AE-1258)</li>
</ul>
"""

st.sidebar.markdown(team_members, unsafe_allow_html=True)

# Initialize the model for efficiency
model = EmotionModel()

# Text input and prediction
user_input = st.text_area("Your Sentence:", height=100)

if st.button("Predict"):
    if user_input:
        predicted_emotion, probabilities = model.predict(user_input)
        emotion_classes = model.model.classes_
        prob_dict = {emotion: prob for emotion, prob in zip(emotion_classes, probabilities)}
        
        # Get the sentiment based on the predicted emotion
        sentiment = model.get_sentiment(predicted_emotion)

        # Display results
        st.success(f"The predicted emotion is: **{predicted_emotion}**")
        st.write(f"The sentiment is: **{sentiment}**")
        st.write("Probabilities for each emotion:")
        st.bar_chart(prob_dict)
    else:
        st.warning("Please enter a sentence.")
