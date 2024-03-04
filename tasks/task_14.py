# N. Слишком сложный пароль

from string import ascii_lowercase, digits, ascii_uppercase

password = input()

complex_password = all([any(char in ascii_lowercase for char in password),
            any(char in ascii_uppercase for char in password),
            any(digit in digits for digit in password)])

def mem_zina(password):
    if len(password) > 10:
        return False
    cnt_digit = 0
    for d in password:
        if d.isdigit():
            cnt_digit += 1
        if cnt_digit > 3:
            return False
    return True
if complex_password:
    print("YES")
else:
    print("NO")

if mem_zina(password):
    print("YES")
else:
    print("NO")