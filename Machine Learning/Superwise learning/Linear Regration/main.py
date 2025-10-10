from sklearn.linear_model import LinearRegression

X = [[1],[2],[3],[4],[5],[6]]
y = [30,55,67,81,83,98]

model = LinearRegression()
model.fit(X , y)

hours = float(input("Enter the Study Time : "))

ans = model.predict([[hours]])
print(ans)

# Equation
print("Equation: y =", model.coef_[0], "* x +", model.intercept_)