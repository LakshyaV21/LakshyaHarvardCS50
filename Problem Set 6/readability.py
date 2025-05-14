from cs50 import get_string

text = get_string("Text: ")
countOfletters = 0
countOfwords = 1
countOfsentences = 0
for i in range(len(text)):
    if text[i].isalpha():
        countOfletters += 1
    elif text[i].isspace():
        countOfwords += 1
    elif text[i] == '.' or text[i] == '!' or text[i] == '?':
        countOfsentences += 1

L = countOfletters / countOfwords * 100
S = countOfsentences / countOfwords * 100
index = 0.0588 * L - 0.29 * S -  15.8
index = round(index)

if index > 16:
    print("Grade 16+")
if index > 1 and index < 17:
    print(f"Grade {index}")
else:
    print("Before Grade 1")
