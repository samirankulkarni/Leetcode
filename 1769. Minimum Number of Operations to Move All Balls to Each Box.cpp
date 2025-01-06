class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        num_boxes = len(boxes)
        operations = [0] * num_boxes

        left_count = 0
        left_sum = 0

        for index in range(num_boxes):
            operations[index] = left_count * index - left_sum
            if boxes[index] == '1':
                left_count += 1
                left_sum += index

        right_count = 0
        right_sum = 0

        for index in range(num_boxes - 1, -1, -1):
            operations[index] += right_sum - right_count * index
            if boxes[index] == '1':
                right_count += 1
                right_sum += index

        return operations
