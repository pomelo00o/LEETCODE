def solver(A, B):
    wordsA = A.split(',')
    wordsB = B.split(',')
    freqs = [0] * 11
    for w in wordsA:
        min_freq = w.count(min(w))
        freqs[min_freq] += 1
    res = []
    for w in wordsB:
        min_freq = w.count(min(w))
        res.append(sum(freqs[:min_freq]))
    return res


if __name__ == '__main__':
    A = 'abcd,aabc,bd'
    B = 'aaa,aa'
    print(solver(A, B))
