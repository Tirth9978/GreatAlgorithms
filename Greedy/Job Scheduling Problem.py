def job_scheduling(jobs):
    """
    jobs = [(start, finish), ...]
    """
    # Step 1: sort by finish time
    jobs.sort(key=lambda x: x[1])
    
    selected = []
    last_finish = -1
    
    for start, finish in jobs:
        if start >= last_finish:
            selected.append((start, finish))
            last_finish = finish
    
    return selected

# Example
jobs = [(1, 3), (2, 3), (4, 5)]   # (start, finish)
print(job_scheduling(jobs))   # → [(1,3), (4,5)] or [(2,3),(4,5)]
