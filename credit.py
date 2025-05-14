import sys


def main():
    credit_card = card_number()
    validate_card(credit_card)


def card_number():
    while True:
        card_number = input("Number: ")
        if card_number.isdigit():
            return card_number


def validate_card(credit_card):
    if len(credit_card) < 13 or len(credit_card) > 16:
        print("INVALID")
        sys.exit(0)

    even, odd = 0, 0
    reverse_digits = credit_card[::-1]

    for i, digit in enumerate(reverse_digits):
        number = int(digit)
        if i % 2 == 1:
            multiple = number * 2
            even += (multiple // 10) + (multiple % 10)
        else:
            odd += number

    checksum = (even + odd) % 10

    if checksum == 0:
        first_digit = int(credit_card[0])
        second_digit = int(credit_card[1]) if len(credit_card) > 1 else 0

        if first_digit == 3 and (second_digit == 4 or second_digit == 7):
            print("AMEX")
        elif first_digit == 5 and 1 <= second_digit <= 5:
            print("MASTERCARD")
        elif first_digit == 4:
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()
