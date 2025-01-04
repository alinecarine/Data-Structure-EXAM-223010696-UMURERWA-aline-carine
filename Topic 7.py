print('Topic 7')
def bucket_sort(data):
    largest = max(data)
    length = len(data)
    size = largest / length

    buckets = [[] for _ in range(length)]
    for i in range(length):
        j = int(data[i] / size)
        if j != length:
            buckets[j].append(data[i])
        else:
            buckets[length - 1].append(data[i])

    for i in range(length):
        buckets[i] = sorted(buckets[i])

    result = []
    for i in range(length):
        result = result + buckets[i]

    return result

# Example usage
priority_data = [23, 45, 12, 67, 34, 89, 10]
sorted_data = bucket_sort(priority_data)
print("Sorted Data:", sorted_data)
