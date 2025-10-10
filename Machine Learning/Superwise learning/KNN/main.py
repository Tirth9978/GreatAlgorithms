from sklearn.neighbors import KNeighborsClassifier

X = [
     [180,7],
     [200,7.5],
     [250 , 8],
     [300 , 8.5],
     [330 , 9],
     [360 , 9.5]
]

# 0 -> Appel 
# 1 -> Orange

y = [0,0,0,1,1,1]

model = KNeighborsClassifier(n_neighbors=3)

model.fit(X , y)

weight = float(input("Enter the Weight : "))
size = float(input("Enter the Size : "))

print(model.predict([[weight , size]]))
