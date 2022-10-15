import numpy as np

m1 = []
m2 = []
m3 = []

tmp1 = []
tmp2 = []
tmp3 = []

size = 500

m1_data = np.genfromtxt('C:\\Users\\ZeroHero\\source\\repos\\PP_Lab1\\PP_Lab1\\mat1.txt', dtype=int)
m2_data = np.genfromtxt('C:\\Users\\ZeroHero\\source\\repos\\PP_Lab1\\PP_Lab1\\mat2.txt', dtype=int)
mult_data = np.genfromtxt('C:\\Users\\ZeroHero\\source\\repos\\PP_Lab1\\PP_Lab1\\mult.txt', dtype=int)

for i in m1_data:
    tmp1.append(i)
    if len(tmp1) == size:
        m1.append(tmp1.copy())
        tmp1.clear()

for j in m2_data:
    tmp2.append(j)
    if len(tmp2) == size:
        m2.append(tmp2.copy())
        tmp2.clear()

for k in mult_data:
    tmp3.append(k)
    if len(tmp3) == size:
        m3.append(tmp3.copy())
        tmp3.clear()

m1 = np.array(m1)
m2 = np.array(m2)
m3 = np.array(m3)
matrix_1 = np.matrix(m1, dtype=int)
matrix_2 = np.matrix(m2, dtype=int)
matrix_mul = np.matrix(m3, dtype=int)

mul = np.dot(matrix_1, matrix_2)
mul = np.array(mul)
matrix_mul = np.array(matrix_mul)

if np.array_equal(mul, matrix_mul):
    print('True')
else:
    print('Something wrong!')
