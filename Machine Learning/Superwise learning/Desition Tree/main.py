from sklearn.tree import DecisionTreeClassifier 

X = [
     [7,2],
     [8,3],
     [9,8],
     [10,9]
]

# 0 : Apple
# 1 : Orange
y = [0,0,1,1]

model = DecisionTreeClassifier()
model.fit(X , y)

print(model.predict([[7,1]]))