import openai

openai.api_key = 'sk-5rHwLGfZQy8LqnQ6KWmQlw'

def create_chatbot(prompt):
    response = openai.Completion.create(
        engine="davinci",
        prompt=prompt,
        max_tokens=1024,
        n=1,
        stop=None,
        temperature=0.5
    )
    return response.choices[0].text.strip()

prompt = "Create a chatbot for money management, which can answer questions like 'What is the best bank for saving money?', 'How to save money on groceries?', 'What is the best way to invest my money?'"

response = create_chatbot(prompt)
print(response)