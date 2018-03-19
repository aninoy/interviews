from sklearn.datasets import load_breast_cancer
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt

cancer = load_breast_cancer()
# print(cancer.DESCR)

# print(cancer.feature_names)
# print(cancer.target_names)
# print(type(cancer.data))
# print(cancer.data.shape)

x_train, x_test, y_train, y_test = train_test_split(cancer.data, cancer.target,
    stratify=cancer.target, random_state=42)
knn = KNeighborsClassifier()
knn.fit(x_train, y_train)
print(knn)
# KNeighborsClassifier(algorithm='auto', leaf_size=30, metric='minkowski',
    # metric_params=None, n_jobs=1, n_neighbors=5, p=2, weights='uniform')
print('Accuracy of kNN, n=5, on training: {:.3f}'.format(knn.score(x_train, y_train)))
print('Accuracy of kNN, n=5, on test: {:.3f}'.format(knn.score(x_test, y_test)))


x_train, x_test, y_train, y_test = train_test_split(cancer.data, cancer.target, stratify=cancer.target, random_state=66)
train_accuracy = []
test_accuracy = []
neighbors = range(1, 11)
for n in neighbors:
    classifier = KNeighborsClassifier(n_neighbors=n)
    classifier.fit(x_train, y_train)
    train_accuracy.append(classifier.score(x_train, y_train))
    test_accuracy.append(classifier.score(x_test, y_test))

plt.plot(neighbors, train_accuracy, label='Train Accuracy')
plt.plot(neighbors, test_accuracy, label='Test Accuracy')
plt.ylabel('Accuracy')
plt.xlabel('# of Neighbors')
plt.legend()
plt.show()
