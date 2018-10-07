
table = [[] for x in range(100)]

def hash_function(x): 
    return x % 10 
    
    
def insert(table,input,value): 
    table[hash_function(input)].append((input,value))
    
    
insert(table,41,'A')
insert(table,93,'B')
insert(table,13,'tangerine')
