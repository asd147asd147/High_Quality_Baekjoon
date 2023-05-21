import sys
import heapq

N = int(sys.stdin.readline())

min_heap = []
max_heap = []
heapq.heapify(min_heap)
heapq.heapify(max_heap)

for _ in range(N):
    num = int(sys.stdin.readline())

    if not len(max_heap):
        heapq.heappush(max_heap, (-num, num))
    elif len(max_heap) == len(min_heap):
        heapq.heappush(max_heap, (-num, num))
    else:
        heapq.heappush(min_heap, num)

    if len(max_heap) and len(min_heap) and max_heap[0][1] >= min_heap[0]:
        a, b = heapq.heappop(max_heap)[1], heapq.heappop(min_heap)

        heapq.heappush(min_heap, a)
        heapq.heappush(max_heap, (-b,b))
    sys.stdout.write(str(max_heap[0][1])+'\n')