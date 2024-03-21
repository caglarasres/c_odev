"""
At the command line, only need to run once to install the package via pip:

$ pip install google-generativeai
"""

import google.generativeai as genai

genai.configure(api_key="AIzaSyDIdyZaBEiJdRQETiavWJnz4Akmt_N73Do")

# Set up the model
generation_config = {
  "temperature": 0.5,
  "top_p": 1,
  "top_k": 1,
  "max_output_tokens": 2048,
}

safety_settings = [
  {
    "category": "HARM_CATEGORY_HARASSMENT",
    "threshold": "BLOCK_MEDIUM_AND_ABOVE"
  },
  {
    "category": "HARM_CATEGORY_HATE_SPEECH",
    "threshold": "BLOCK_MEDIUM_AND_ABOVE"
  },
  {
    "category": "HARM_CATEGORY_SEXUALLY_EXPLICIT",
    "threshold": "BLOCK_MEDIUM_AND_ABOVE"
  },
  {
    "category": "HARM_CATEGORY_DANGEROUS_CONTENT",
    "threshold": "BLOCK_MEDIUM_AND_ABOVE"
  },
]

model = genai.GenerativeModel(model_name="gemini-1.0-pro",
                              generation_config=generation_config,
                              safety_settings=safety_settings)
myinputstr=input("HOW DO YOU FEEL TODAY:    ")

prompt_parts = [
    """Tell me whether the following sentence's feeling situation.Result should one of those: joy, love, gratitude, peace, hope, excitement, pride, amusement, passion, contentment, sadness, anger, fear, guilt, shame, frustration, disgust, loneliness, despair, jealousy, tiredness.Examples are below . The sentece to be explained
    :""" + myinputstr+"""
    # Fear
    "Sentence: The dark and unfamiliar forest path made me shiver.",
    "Sentiment: Fear",
    "Sentence: The sudden loud noise startled me, and I jumped.",
    "Sentiment: Fear",
    "Sentence: The news report about the global pandemic caused a sense of unease.",
    "Sentiment: Fear",

    # Anger
    "Sentence: It infuriates me when people are treated unfairly.",
    "Sentiment: Anger",
    "Sentence: The constant traffic jam made me feel frustrated and angry.",
    "Sentiment: Anger",
    "Sentence: His careless remark triggered a surge of anger in me.",
    "Sentiment: Anger",

    # Joy
    "Sentence: Winning the lottery brought immense joy to my life.",
    "Sentiment: Joy",
    "Sentence: Spending time with loved ones fills me with happiness and contentment.",
    "Sentiment: Joy",
    "Sentence: Achieving my goal after months of hard work brought a feeling of elation.",
    "Sentiment: Joy",

    # Sadness
    "Sentence: The loss of a loved one left me feeling deeply saddened.",
    "Sentiment: Sadness",
    "Sentence: Feeling isolated and alone can lead to feelings of sadness.",
    "Sentiment: Sadness",
    "Sentence: Disappointment about a canceled trip brought a wave of sadness.",
    "Sentiment: Sadness",

    # Contempt
    "Sentence: I find his arrogant and disrespectful behavior contemptible.",
    "Sentiment: Contempt",
    "Sentence: Their constant negativity breeds contempt in me.",
    "Sentiment: Contempt",
    "Sentence: I hold no respect for those who exploit others for their own gain.",
    "Sentiment: Contempt",

    # Disgust
    "Sentence: The sight of the overflowing trash can filled me with disgust.",
    "Sentiment: Disgust",
    "Sentence: The thought of cruelty to animals is utterly repulsive.",
    "Sentiment: Disgust",
    "Sentence: The offensive remarks made me feel disgusted and nauseated.",
    "Sentiment: Disgust",

    # Surprise
    "Sentence: I was surprised to hear that he had won the award.",
    "Sentiment: Surprise",
    "Sentence: The unexpected turn of events left me speechless in surprise.",
    "Sentiment: Surprise",
    "Sentence: Discovering a hidden treasure in the attic was a delightful surprise.",
    "Sentiment: Surprise"
    """
]

response = model.generate_content(prompt_parts)
print(response.text)