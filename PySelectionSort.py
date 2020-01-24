#this program illustrates selection sort in python 3
a=[12,21,6,85,1,19]
for i in range(len(a)):
    small=i                      #store the index of i(th) element in small
    for j in range(i+1,len(a)):  
        if a[small]>a[j]:               #compare the element with index small with the elements ahead of it
            small=j                     #if any element is found smaller than the one which is compared store its index in 'small'
            a[small],a[i]=a[i],a[small] #swap the element at the index 'small' with that at the index 'i' so as the smallest element comes first in the array
    print(a)   #stepwise sorting is showed
