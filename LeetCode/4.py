def findMedianSortedArrays(self, nums1, nums2):
    merged = nums1 + nums2

    merged.sort()

    total = len(merged)

    if total % 2 == 1:
            return float(merged[total // 2])
    else:
        meio1 = merged[total // 2 - 1]
        meio2 = merged[total // 2]
        return (float(meio1) + float(meio2)) / 2.0
    
nums1 = [1, 2]
nums2 = [3, 4]
result = findMedianSortedArrays(nums1, nums2)
print(result)