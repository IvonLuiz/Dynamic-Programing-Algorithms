import itertools

def check_denis_function(N, M, coefficients):
    # Generate all possible unique tuples (rankings)
    ranks = list(itertools.permutations(range(1, M + 1), N))
    
    function_values = set()
    
    for rank in ranks:
        func_value = sum(coefficients[i] * rank[i] for i in range(N))
        
        if func_value in function_values:
            return "Try again later, Denis..."
        
        function_values.add(func_value)
    
    return "Lucky Denis!"

def main():
    try:
        while True:
            # Read the input
            line = input().strip()
            if not line:
                break
            
            N, M = map(int, line.split())
            coefficients = list(map(int, input().strip().split()))
            
            # Check the function
            result = check_denis_function(N, M, coefficients)
            print(result)
    
    except EOFError:
        pass

if __name__ == "__main__":
    main()
