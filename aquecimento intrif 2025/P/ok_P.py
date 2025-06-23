import sys

# Aumenta o limite de recursão para caminhos de busca profundos (até M estradas)
sys.setrecursionlimit(2050)

def find_tour(start_node, current_node, path, visited_roads, M, roads, adj):
    """
    Função recursiva (DFS) que busca por um passeio válido.
    Retorna True se uma solução for encontrada e impressa, False caso contrário.
    """
    # Caso base: O caminho incluiu todas as estradas
    if len(path) == M:
        # Verifica se o passeio terminou na cidade inicial 
        if current_node == start_node:
            first_road_color = roads[path[0]][2]
            last_road_color = roads[path[-1]][2]
            
            # Verifica se a primeira e a última estrada têm cores diferentes 
            if first_road_color != last_road_color:
                print(start_node) # 
                print(*path) # 
                return True
        return False

    # Passo recursivo: Explora as próximas estradas possíveis
    last_road_color = roads[path[-1]][2]
    
    for edge in adj[current_node]:
        road_id = edge['id']
        road_color = edge['color']
        
        # A estrada não pode ter sido visitada 
        if not visited_roads[road_id]:
            # A cor da próxima estrada não pode ser igual à da anterior 
            if road_color != last_road_color:
                visited_roads[road_id] = True
                path.append(road_id)
                
                if find_tour(start_node, edge['neighbor'], path, visited_roads, M, roads, adj):
                    return True
                
                path.pop()
                visited_roads[road_id] = False
    return False

def solve():
    """
    Função principal para ler um único caso de teste, verificar condições e encontrar o passeio.
    """
    try:
        line = sys.stdin.readline()
        if not line.strip():
            return False
        N, M, K = map(int, line.split())
    except (IOError, ValueError):
        return False

    adj = [[] for _ in range(N + 1)]
    roads = [None] * (M + 1)
    degrees = [0] * (N + 1)

    for road_id in range(1, M + 1):
        u, v, c = map(int, sys.stdin.readline().split()) # 
        roads[road_id] = (u, v, c)
        adj[u].append({'neighbor': v, 'id': road_id, 'color': c})
        adj[v].append({'neighbor': u, 'id': road_id, 'color': c})
        degrees[u] += 1
        degrees[v] += 1

    # MODIFICAÇÃO: Ordena as estradas de cada cidade por ID decrescente.
    # Assim, a busca sempre tentará a estrada de maior ID primeiro.
    for i in range(1, N + 1):
        if adj[i]:
            adj[i].sort(key=lambda edge: edge['id'], reverse=True)

    # --- Verificações de pré-requisitos ---
    start_node = -1
    nodes_with_edges = 0
    for i in range(1, N + 1):
        if degrees[i] > 0:
            nodes_with_edges += 1
            if start_node == -1:
                start_node = i
    
    if M > 0 and start_node == -1:
        print(-1) # 
        return True

    if M == 0:
        print(1 if N >= 1 else -1)
        if N >= 1: print()
        return True

    # 1. Verificação de Conectividade
    q = [start_node]
    visited_component = {start_node}
    head = 0
    while head < len(q):
        u = q[head]; head += 1
        for edge in adj[u]:
            v = edge['neighbor']
            if v not in visited_component:
                visited_component.add(v)
                q.append(v)
    
    if len(visited_component) != nodes_with_edges:
        print(-1) # 
        return True

    # 2. Verificação de Grau (Circuito Euleriano)
    for i in range(1, N + 1):
        if degrees[i] % 2 != 0:
            print(-1) # 
            return True

    # 3. Verificação da Restrição de Cor por Vértice
    for i in range(1, N + 1):
        if degrees[i] > 0:
            color_counts = {}
            for edge in adj[i]:
                color = edge['color']
                color_counts[color] = color_counts.get(color, 0) + 1
            
            for color in color_counts:
                if color_counts[color] > degrees[i] // 2:
                    print(-1) # 
                    return True

    # --- Busca com Backtracking ---
    visited_roads = [False] * (M + 1)
    solution_found = False
    
    for edge in adj[start_node]:
        path = [edge['id']]
        visited_roads[edge['id']] = True
        
        if find_tour(start_node, edge['neighbor'], path, visited_roads, M, roads, adj):
            solution_found = True
            break
        
        visited_roads[edge['id']] = False

    if not solution_found:
        print(-1) # 
    
    return True

if __name__ == "__main__":
    while solve():
        pass