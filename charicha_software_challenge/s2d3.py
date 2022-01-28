def fib(n):
    if(n <= 1):
        return n
    a = 0
    b = 0
    t = 0
    for i in range(n):
        t = b
        b = a + b
        a = t
    return b

def list_to_string(ls):
    str1 = ""
    for ele in ls:
        str1 += str(ele)
    return str1

def around_fib(n):
    fn = fib(n)
    ls = [int(x) for x in str(fn)]



    nc = [0] * len(ls);
    cnt = 0
    ld = 0
    ck = []

    for i in range(len(ls)):
        if len(ck) == 25:
            ck.clear()
            ck.append(ls[i])
        else:
            ck.append(ls[i])
        d = ls[i]
        if nc[d] > cnt:
            cnt = nc[d]
            ld = d
        elif nc[d] == cnt:
            if d < ld:
                ld = d

    return "Last chunk " + list_to_string(ls) + "; Max is " + str(cnt) + " for digit " + str(ld) + "";

