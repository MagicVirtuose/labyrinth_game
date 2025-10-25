import random

n = 75
m = 75

def generate_labyrinth():
    labyrinth = []

    for i in range(n):
        labyrinth.append([])
        for j in range(m):
            labyrinth[i].append('|')
    
    x = random.randint(0,n)
    y = random.randint(0,m)
    labyrinth[x][y] = ' '
    frontiers = get_frontiers(labyrinth,x,y)
    
    
    
    while len(frontiers) != 0:

        print("frontiers list :", frontiers)
        #Choose a random frontier (ie. its coordinates)
        k = random.randint(0, len(frontiers)-1 )
        (fx, fy) = frontiers[k]
        frontiers.pop(k)

        #Connect the chosen frontier and a random neighbor.
        neighbors = get_neighbors(labyrinth, fx, fy)
        if neighbors:
            nx , ny = neighbors[random.randint(0, len(neighbors)-1)]
            labyrinth[(fx + nx) //2][(fy + ny)//2] = ' '
            labyrinth[fx][fy] = ' '
        
        #Add the frontiers of the chosen frontier to the frontier list.
        new_frontiers = get_frontiers(labyrinth, fx, fy)
        for f in new_frontiers:
            if f not in frontiers:
                frontiers.append(f)


    for i in range(n):
        if labyrinth[i][0] == ' ':
            labyrinth[i][0] = '|'
        if labyrinth[i][-1] == ' ':
            labyrinth[i][-1] = '|'  
    for j in range(m):
        if labyrinth[0][j] == ' ':
            labyrinth[0][j] = '|'
        if labyrinth[-1][j] == ' ':
            labyrinth[-1][j] = '|'  
            
    return labyrinth


def get_frontiers(labyrinth, x, y):

    frontiers = []
    tmp = [(0,2),(2,0),(0,-2),(-2,0)]

    for i in range(len(tmp)):
        a = tmp[i][0]
        b = tmp[i][1]

        if (0 <= x + a < n) and (0 <= y + b < m) :
            if labyrinth[x+a][y+b] == '|':
                frontiers.append((x + a , y + b) )

    return frontiers


def get_neighbors(labyrinth, x, y):
    neighbors = []
    tmp = [(0,2),(2,0),(0,-2),(-2,0)]

    for i in range(len(tmp)):
        a = tmp[i][0]
        b = tmp[i][1]

        if (0 <= x + a < n) and (0 <= y + b < m):
            
            if labyrinth[x+a][y+b] == ' ':
                neighbors.append((x + a, y + b) )
    
    return neighbors


def save_labyrinth(labyrinth, i):
    with open("../levels/"+str(i)+".txt", "a") as f:
        f.truncate(0)

        for i in range(len(labyrinth)):
            
            for j in range(len(labyrinth[i])):

                f.write(labyrinth[i][j])
            f.write("\n")

if __name__ == "__main__":

    for i in range(0, 6):

        save_labyrinth(generate_labyrinth(),i)