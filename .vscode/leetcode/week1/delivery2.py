def solution(S):
    # write your code in Python 3.6
    stack = []
    op = ["DUP", "POP", "+", "-"]

    def func_dup():
        stack.append(stack[-1])

    def func_pop():
        stack.pop()

    def func_plus():
        stack[-2] = stack[-1]+stack[-2]
        stack.pop()

    def func_minus():
        stack[-2] = stack[-1]-stack[-2]
        stack.pop()
    functions = {"DUP": func_dup,
                 "POP": func_pop,
                 "+": func_plus,
                 "-": func_minus
                 }
    str_list = S.split()
    try:
        for cur in str_list:
            if(cur in op):
                func = functions[cur]
                func()
            else:
                stack.append(int(cur))
        return stack[-1]
    except (IndexError):
        return -1
    pass


print(solution("5 6 + -"))
