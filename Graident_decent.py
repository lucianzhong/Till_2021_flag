import numpy as np
import matplotlib.pyplot as plt
X = np.array([np.ones(100),np.random.rand(100)])
y = np.dot([4, 3], X) + np.random.rand(100)
plt.scatter(X[1, :], y)
plt.show()
print(X.shape)
print(y.shape)
print('gradient descent start')
alpha = 0.01
num_iter = 1000


def gradient_descent(theta, X, y, alpha, num_iter):
    loss_history = np.zeros(num_iter)
    theta_history = np.zeros((num_iter, 2))
    m = len(y)
    for i in range(num_iter):
        y_pred = np.dot(theta, X)
        theta = theta - alpha/m*np.dot((y_pred - y), X.T)
        loss = 1/(2*m) * np.sum(np.square(y_pred - y))
        theta_history[i, :] = theta
        loss_history[i] = loss
        if i%100 == 1:
            print('theta is',theta)
            print('current loss is',loss)
    return theta, theta_history, loss_history




theta_ini = np.random.randn(2)
theta, theta_history, loss_history = gradient_descent(theta_ini,X,y,alpha, num_iter)

residual = np.zeros((len(y)-1))
for i in range(len(y)-1):
    residual[i] = loss_history[i] - loss_history[i+1]

print(theta)

plt.plot(loss_history)
plt.show()
plt.plot(residual)
plt.show()