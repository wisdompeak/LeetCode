def findMedianSortedArrays(nums1, nums2):
    n1, n2 = len(nums1), len(nums2)
    if n1 > n2:
        return findMedianSortedArrays(nums2, nums1) #cambian si es mas grande de matrices

    n = n1 + n2 #el total de todos los numeros

    left = (n1 + n2 + 1) // 2  #longi de la izquierda mitad
    #de aqui abajo aplicamos busqueda binaria
    low, high = 0, n1

    while low <= high:
        mid1 = (low + high) // 2
        mid2 = left - mid1

        #aqui calculamos los l y r que nos confundio en lo escrito

        l1, l2, r1, r2 = float('-inf'), float('-inf'), float('inf'), float('inf')

        if mid1 < n1:
            r1 = nums1[mid1]
        if mid2 < n2:
            r2 = nums2[mid2]
        if mid1 - 1 >= 0:
            l1 = nums1[mid1 - 1]
        if mid2 - 1 >= 0:
            l2 = nums2[mid2 - 1]

        if l1 <= r2 and l2 <= r1:
            if n % 2 == 1:
                return max(l1, l2)
            else:
                return (float(max(l1, l2)) + float(min(r1, r2))) / 2.0

        elif l1 > l2:
            high = mid1 - 1
        else:
            low = mid1 + 1
    return 0
