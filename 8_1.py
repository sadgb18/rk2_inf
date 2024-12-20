A = 0b101101
B = 0b110011

and_result = A & B

sum_result = A + B

print(f"Результат операции AND: {bin(and_result)[2:].zfill(6)}")  # Преобразуем результат в двоичную строку
print(f"Результат сложения: {bin(sum_result)[2:]}")  # Преобразуем результат в двоичную строку
