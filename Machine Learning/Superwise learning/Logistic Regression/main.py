from sklearn.linear_model import LogisticRegression
import numpy as np
import matplotlib.pyplot as plt


X = [[1],[2],[3],[4],[5]] # Input 
y = [0,0,0,1,1] # Result

model = LogisticRegression()

model.fit(X , y)

print(model.predict([[0]]))

# Generate values for plotting
x_values = np.linspace(0, 6, 100).reshape(-1, 1)  # from 0 to 6
y_prob = model.predict_proba(x_values)[:, 1]      # probability of class 1

# Plot
plt.scatter(X, y, color="red", label="Data Points")
plt.plot(x_values, y_prob, color="blue", label="Logistic Curve")
plt.axhline(0.5, color="green", linestyle="--", label="Decision Boundary")
plt.xlabel("X")
plt.ylabel("Probability of y=1")
plt.title("Logistic Regression Fit")
plt.legend()
plt.show()