def solver(s):
    _time_ = ''
    if s[0] == '?':
        if s[1] == '?' or int(s[1]) <= 3:
            _time_ += '2'
        else:
            _time_ += '1'
    else:
        _time_ += s[0]
    if s[1] == '?':
        if int(_time_[0]) == 2:
            _time_ += '3'
        else:
            _time_ += '9'
    else:
        _time_ += s[1]
    _time_ += s[2]
    if s[3] == '?':
        _time_ += '5'
    else:
        _time_ += s[3]
    if s[4] == '?':
        _time_ += '9'
    else:
        _time_ += s[4]
    return _time_


if __name__ == '__main__':
    s = '?4:5?'
    print(solver(s))
