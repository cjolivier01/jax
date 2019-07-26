from autograd import grad

def f(z):
  x, y = real(z), imag(z)
  return u(x, y) + v(x, y) * 1j


def grad_f(z):
  x, y = real(z), imag(z)
  return grad(u, 0)(x, y) - i * grad(u, 1)(x, y)


