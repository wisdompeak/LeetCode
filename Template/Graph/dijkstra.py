    
import heapq
class Solution:

    def dijkstra(n: int, graph: list[list]):

        starting_node = 0
        distances = {node: float('inf') for node in range(n)}
        distances[starting_node] = 0
        
        pq = [(0, starting_node)]

        while len(pq) > 0:

            current_distance, current_node = heapq.heappop(pq)

            if current_distance > distances[current_node]:
                continue

            for neighbor, weight in graph[current_node]:
                distance = current_distance + weight
                # Only consider this new path if it's better than any path we've
                # already found.
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    heapq.heappush(pq, (distance, neighbor))

        return distances


n = 3
graph = {0: [(1, 2), (2, 4)], 1: [(0, 2), (2, 1)], 2: [(1, 1), (0, 4)]}
print(Solution.dijkstra(n, graph))

