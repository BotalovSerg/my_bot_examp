# O. Файлы-файлы
import re
# s =  input()

st = "abacaba123.hlm и 123.brhl интересуют его, а a.brhl.py , также hlm.cpp .brhl нет."

pattern = "\w+\.(?:hlm|brhl)[^\.]"
res = re.findall(pattern, st)
print(res)