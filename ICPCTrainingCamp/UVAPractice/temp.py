def duo(faceup,inhand):
    start = inhand.split(" ")
    #print(faceup, inhand)
    topofdeck = faceup
    placedown=[faceup]
    for num in range(len(start)):
        for card in start:
            similar=0
            for j in range(0,3):
                if card[j] == topofdeck[j]:
                    similar += 1
            if similar >= 2:
                placedown.append(card)
                start.remove(card)
                topofdeck=card
            else:
                pass
    final= " ".join(placedown)
    return final

faceup = input()
inhand = input()
#print(faceup)
#print(inhand)
result = duo(faceup, inhand)
print(result)
print()


