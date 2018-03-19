from sklearn.datasets import load_breast_cancer
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt

cancer = load_breast_cancer()

x_train, x_test, y_train, y_test = train_test_split(cancer.data, cancer.target, stratify=cancer.target, random_state=42)

lr = LogisticRegression()
lr.fit(x_train, y_train)

print('Accuracy on training subset: {:.3f}'.format(lr.score(x_train, y_train)))
print('Accuracy on test subset: {:.3f}'.format(lr.score(x_test, y_test)))

lr100 = LogisticRegression(C=100)
lr100.fit(x_train, y_train)
print('Accuracy on training subset: {:.3f}'.format(lr100.score(x_train, y_train)))
print('Accuracy on test subset: {:.3f}'.format(lr100.score(x_test, y_test)))

lr001 = LogisticRegression(C=0.01)
lr001.fit(x_train, y_train)
print('Accuracy on training subset: {:.3f}'.format(lr001.score(x_train, y_train)))
print('Accuracy on test subset: {:.3f}'.format(lr001.score(x_test, y_test)))

plt.plot(lr.coef_.T, 'o', label='C=1')
plt.plot(lr100.coef_.T, '^', label='C=100')
plt.plot(lr001.coef_.T, 'v', label='C=0.01')
plt.xticks(range(cancer.data.shape[1]), cancer.feature_names, rotation=90)
plt.hlines(0, 0, cancer.data.shape[1])
plt.ylim(-5, 5)
plt.xlabel('Coefficient Index')
plt.ylabel('Coefficient Magnitude')
plt.legend()
plt.show()
