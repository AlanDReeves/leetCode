def fizzBuzz(n):
    for i in range(n):
        if i == n:
            if i % 3 == 0 and i % 5 == 0:
                print("FizzBuzz", end=' ',flush=True)
            elif i % 3 == 0: 
                print("Fizz", end=' ', flush=True)
            elif i % 5 == 0:
                print("Buzz", end=" ", flush=True)
            else:
                print(i, end=' ', flush=True)
        elif i % 3 == 0 and i % 5 == 0:
            print("FizzBuzz")
        elif i % 3 == 0: 
            print("Fizz")
        elif i % 5 == 0:
            print("Buzz")
        else:
            print(i)

fizzBuzz(15)