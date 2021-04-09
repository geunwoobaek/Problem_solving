from constraint import *
problem = Problem()


nationality = ["영국", "스웨덴", "독일", "노르웨이", "덴마크"] 
pet = ["개", "고양이", "새", "말", "물고기"]
cigarett = ["던힐", "블렌드","펠몰", "프린스", "블루매스터"] 
colour = ["빨강", "초록", "노랑", "파랑", "하양"]
beverage = ["커피", "우유", "맥주", "생수", "차"]
criteria = nationality + pet + cigarette + colour + beverage
problem.addVariables(criteria,[1,2,3,4,5])

problem.addConstraint(AllDifferentConstraint(), nationality)
problem.addConstraint(AllDifferentConstraint(), pet)
problem.addConstraint(AllDifferentConstraint(), cigarett)
problem.addConstraint(AllDifferentConstraint(), colour)
problem.addConstraint(AllDifferentConstraint(), beverage)

problem.addConstraint(lambda e, r: e == r, ["영국","빨강"]) 
problem.addConstraint(lambda s, d: s == d, ("스웨덴","개")) 
problem.addConstraint(lambda c, g: c == g, ("커피","초록")) 
problem.addConstraint(lambda u, t: u == t, ("덴마크","차"))
problem.addConstraint(lambda g, i: g-i == 1, ("하양","초록"))
problem.addConstraint(lambda o, s: o == s, ("펠몰","새")) 
problem.addConstraint(lambda k, y: k == y, ("던힐","노랑")) 
problem.addConstraint(InSetConstraint([3]), ["우유"]) 
problem.addConstraint(InSetConstraint([1]), ["노르웨이"]) 
problem.addConstraint(lambda c, f: abs(c-f) == 1, ("블렌드","고양이")) 
problem.addConstraint(lambda k, h: abs(k-h) == 1, ("던힐","말")) 
problem.addConstraint(lambda l, o: l == o, ["블루매스터","맥주"]) 
problem.addConstraint(lambda j, p: j == p, ["독일","프린스"])
problem.addConstraint(lambda k, h: abs(k-h) == 1, ("노르웨이","파랑"))
solution = problem.getSolutions()[0]

for i in range(1,6):
    for x in solution:
        if solution[x] == i:
            print str(i), x
