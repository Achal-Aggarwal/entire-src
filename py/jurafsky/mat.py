#sg
#This script creates the subs matrix
#note on scoring :
#The value subs[x, y] is the number of times x was wrongly typed as y.
#Egsuppose we have "affort" wrongly typed as "afforr" will cause subs[t, r] += 1
#the value trans[x, y] is the number of times "xy" was written as "yx".
#Eg, "would" typed as "woudl" will cause trans[l][d] += 1
def createMatrices(errorCorrectFileName):
    
    correctionFile = open(errorCorrectFileName, "r")
    
    subs = [[0 for i in range(26)] for j in range(26)]
    trans = [[0 for i in range(26)] for j in range(26)]
    de = [[0 for i in range(26)] for j in range(26)]
    ins = [[0 for i in range(26)] for j in range(26)]
    
    for correctionEntry in correctionFile:
    
        '''
        each correction entry is of the form =>
        correct => incorrect1, incorrect2,..., incorrect n
        '''
        correctionEntry = correctionEntry.strip().lower()
        entrySplit = correctionEntry.split(':')
        if(len(entrySplit) < 2):
            continue
        
        cw = entrySplit[0].strip().lower()
        from collections import defaultdict
        charBi = defaultdict(int) #bigram frequency
        char = defaultdict(int) #char frquency
        bigrams = (cw[i] + cw[i + 1] for i in range(len(cw) - 1))
        for bg in bigrams:
            charBi[bg] += 1
            char[cw[i]] += 1
        char[cw[len(cw) - 1]] += 1


        icwl = entrySplit[1].split(',')
    
        for icw in icwl:
            icw = icw.strip().lower()
            if (len(icw) == len(cw)): #lengths equal? : either substitution or xposition (Assuming that either of the 4 errors happens at a time)
               
                #test for substitution
    
                for i in range(len(cw)): #iterate through characters and find out same characters
                    if(cw[i] != icw[i]): #some character substituted
                        ri = ord(cw[i]) - 97 #row index
                        ci = ord(icw[i]) - 97 #column index
                        #print ri, ci
                        if(ri <= 25 and ri >= 0 and ci <= 25 and ci >= 0): #avoiding unicode
                            subs[ri][ci] += 1
    
                #test for transposition
                
                for i in range(len(cw) - 1):
                    #we test if ci,ci+1 has been typed as ci+1,ci 
                    if(cw[i] == icw[i + 1] and cw[i + 1] == icw[i]): #Xposition detected
                        ri = ord(cw[i]) - 97 #row index
                        ci = ord(cw[i + 1]) - 97 #column index
                        #print ri, ci
                        if(ri <= 25 and ri >= 0 and ci <= 25 and ci >= 0): #avoiding unicode
                            trans[ri][ci] += 1
    
            elif(len(cw) > len(icw)): #correct word is longer, deletion happened
                '''i,j element of the deletion matrix dl stores the number of 
                times i was written instead of ij'''
                i = 0
                #skip the common prefix
                while( i < len(icw) and icw[i] == cw[i]):
                    i += 1
                    #in *any* case, cw[i] now refers to the deleted character
                    ri = ord(icw[i - 1]) - 97 #row index
                    ci = ord(cw[i]) - 97 #column index
                    '''now i points to the character that was deleted
                    so, icw[i - 1] was written instead of cw[i - 1],cw[i]'''
                    if(ri >= 0 and ri <= 25 and ci >= 0 and ci <= 25):
                        de[ri][ci] += 1
            
            else: #length of incorrect word is longer than correct word, insertion
                '''i,j element of the deletion matrix dl stores the number of 
                times i was written instead of ij'''
                i = 0
                  #skip the common prefix
                  
                while( i < len(cw) and icw[i] == cw[i]):
                    i += 1
                    '''in *any* case, icw[i] now refers to the inserted character
                    We should have typed icw[i - 1] only, but we have written icw[i]
                    '''
                    ri = ord(icw[i - 1]) - 97 #row index
                    ci = ord(icw[i]) - 97 #column index
                    '''now i points to the character that was deleted
                    so, icw[i - 1] was written instead of cw[i - 1],cw[i]'''
                    if(ri >= 0 and ri <= 25 and ci >= 0 and ci <= 25):
                        ins[ri][ci] += 1
    tCount = 0
    iCount = 0
    sCount = 0
    dCount = 0
    for i in range(26):
        for j in range(26):
            tCount += trans[i][j]
            dCount += de[i][j]
            sCount += subs[i][j]
            iCount += ins[i][j]
    for i in range(26):
        for j in range(26):
            trans[i][j] = float(trans[i][j]) / tCount
            subs[i][j] = float(subs[i][j]) / sCount
            ins[i][j] = float(ins[i][j]) / iCount
            de[i][j] = float(de[i][j]) / dCount
    #print tCount, dCount, iCount, sCount
    return {'subs':subs, 'trans':trans, 'del':de, 'ins':ins, 'charBi':charBi, 'char':char}
