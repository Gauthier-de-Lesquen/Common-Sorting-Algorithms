function u_swap(arr, a, b)
    local temp = arr[a]
    arr[a] = arr[b]
    arr[b] = temp
end

function u_slice(arr, startIndex, endIndex)
    local result = {}
    for i = startIndex, endIndex do
        if arr[i] ~= nil then
            table.insert(result, arr[i])
        end
    end
    return result
end

function binarySearch(arr, target)
    left = 1
    right = #arr
    while left <= right do
        mid = (left + right) // 2
        if arr[mid] == target then
            return mid
        elseif arr[mid] < target then
            left = mid + 1
        else
            right = mid - 1
        end
    end
    return -1
end

function linearSearch(arr, target)
    for i = 1, #arr do
        if arr[i] == target then
            return i
        end
    end
    return -1
end

function bubbleSort(arr)
    for i = 1, #arr do
        local swapped = false

        for j = 1, #arr - i do
            if arr[j] > arr[j + 1] then
                u_swap(arr, j, j + 1)
                swapped = true
            end
        end

        if not swapped then break end
    end
end

        
function selectionSort(arr)
    for i = 1, #arr do
        local minIndex = i
        for j = i + 1, #arr do
            if arr[j] < arr[minIndex] then 
                minIndex = j
            end
        end
                
        if minIndex ~= i then
            u_swap(arr, i, minIndex)
        end
    end
end

function insertionSort(arr)
    for i = 2, #arr do
        local key = arr[i]
        local j = i - 1

        while j >= 1 and arr[j] > key do
            arr[j + 1] = arr[j]
            j = j - 1
        end
        arr[j + 1] = key
    end
end

        
function u_partition(arr, low, high)
    local pivot = arr[high]
    local i = low - 1

    for j = low, high - 1 do
        if arr[j] <= pivot then
            i = i + 1
            u_swap(arr, i, j)
        end
    end

    u_swap(arr, i + 1, high)
    return i + 1
end

function u_quickSortRec(arr, low, high)
    if low < high then
        local pi = u_partition(arr, low, high)

        u_quickSortRec(arr, low, pi - 1)
        u_quickSortRec(arr, pi + 1, high)
    end
end

function quickSort(arr)
    if #arr <= 1 then return arr end
    u_quickSortRec(arr, 1, #arr)
end
    
function mergeSort(arr)
    if #arr <= 1 then return arr end

    local mid = math.floor(#arr / 2)
    local left = u_slice(arr, 1, mid)
    local right = u_slice(arr, mid + 1, #arr)

    mergeSort(left)
    mergeSort(right)

    u_merge(arr, left, right)
end

function u_merge(arr, left, right)
    local i = 1
    local j = 1
    local k = 1

    while i <= #left and j <= #right do
        if left[i] < right[j] then
            arr[k] = left[i]
            i = i + 1
        else
            arr[k] = right[j]
            j = j + 1
        end
        k = k + 1
    end

    while i <= #left do
        arr[k] = left[i]
        i = i + 1
        k = k + 1
    end

    while j <= #right do
        arr[k] = right[j]
        j = j + 1
        k = k + 1
    end
end

function u_heapify(arr, size, i)
    local largest = i
    local left = 2 * i
    local right = 2 * i + 1

    if left <= size and arr[left] > arr[largest] then
        largest = left
    end
    if right <= size and arr[right] > arr[largest] then
        largest = right
    end

    if largest ~= i then
        u_swap(arr, i, largest)
        u_heapify(arr, size, largest)
    end
end

function heapSort(arr)
    local n = #arr

    for i = math.floor(n / 2), 1, -1 do
        u_heapify(arr, n, i)
    end

    for i = n, 2, -1 do
        u_swap(arr, 1, i)
        u_heapify(arr, i - 1, 1)
    end
end
