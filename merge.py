nums1 = [1,2,3,0,0,0]
nums2 = [2,5,6]
m = 3
n = 3

def merge(nums1, m, nums2, n) -> None:
    p1 = m - 1 # note that len(nums1) = m+n, pointer is to the end of m - 1
    p2 = n - 1
    # instructions state that nums1 is set to m+n and padded with zeros to constrain the max length
    p3 = m+n-1
    # I drew this out and want to verify how many times it enters the while loop
    # I got 5
    counter = 0 
    # use the pointers for the loop termination, must drop below 0 indicated we've exhausted an array
    while p1 >= 0 and p2 >= 0:
        counter += 1
        if nums1[p1] >= nums2[p2]:
            # covers case that they are the same 
            nums1[p3] = nums1[p1]
            p1 -= 1
        else:
            # nums[p2] is larger
            nums1[p3] = nums2[p2]
            p2 -= 1
        # decrement the main pointer
        p3 -= 1
    
    print(nums1)
    print(counter)
        
        
        
    
            
        
merge(nums1, m, nums2, n)