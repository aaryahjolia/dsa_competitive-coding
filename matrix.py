def search_matrix(matrix, target):
    if not matrix or not matrix[0]:
        return False

    rows = len(matrix)
    cols = len(matrix[0])

    # Start at the top-right corner
    row = 0
    col = cols - 1

    while row < rows and col >= 0:
        if matrix[row][col] == target:
            return True
        elif matrix[row][col] < target:
            row += 1
        else:
            col -= 1

    return False


matrix = [
    [1, 2, 3, 4, 5],
    [2, 6, 7, 8, 9],
    [3, 10, 19, 16, 22],
    [4, 13, 14, 17, 24],
    [5, 21, 23, 26, 30]
]

target = 21
result = search_matrix(matrix, target)
print(f"Element {target} found in the matrix: {result}")
