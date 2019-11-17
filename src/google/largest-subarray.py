def solver(A, k):
    first_idx = 0
    for x in range(1, len(A) - k + 1):
        for i in range(k):
            if A[first_idx + i] < A[x + i]:
                first_idx = x
                break
            elif A[first_idx + i] > A[x + i]:
                break
            else:
                continue
    return A[first_idx:first_idx + k]


if __name__ == '__main__':
    A = [1, 4, 3, 2, 5]
    k = 4
    print(solver(A, k))
