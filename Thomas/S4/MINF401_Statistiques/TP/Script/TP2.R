 GILETJAUNE=read.table("D:/cours/Cours-L2/Thomas/S4/MINF401_Statistiques/TP/Script/iris.dat",header=TRUE)
mean(GILETJAUNE$Sepal.Length)
par(mfrow=c(2,2))
n=(max(GILETJAUNE$Sepal.Length)-min(GILETJAUNE$Sepal.Length))/0.2
p=(max(GILETJAUNE$Petal.Length)-min(GILETJAUNE$Petal.Length))/0.2
m=(max(GILETJAUNE$Sepal.Width)-min(GILETJAUNE$Sepal.Width))/0.2
q=(max(GILETJAUNE$Petal.Width)-min(GILETJAUNE$Petal.Width))/0.2
hist(GILETJAUNE$Sepal.Length,freq=FALSE,col=rainbow(20),breaks=n,main="Histogramme longueur Sépales")
hist(GILETJAUNE$Sepal.Width,freq=FALSE,col="yellow",breaks=m,main="Histogramme largeur Sépales")
hist(GILETJAUNE$Petal.Width,freq=FALSE,col="yellow",breaks=q,main="Histogramme largeur pétales")
hist(GILETJAUNE$Petal.Length,freq=FALSE,col=rainbow(20),breaks=p,main="Histogramme longueur pétales")
cov(GILETJAUNE$Sepal.Length,GILETJAUNE$Sepal.Width)
cov(GILETJAUNE$Petal.Length,GILETJAUNE$Petal.Width)
cor(GILETJAUNE$Sepal.Length,GILETJAUNE$Sepal.Width)
cor(GILETJAUNE$Petal.Length,GILETJAUNE$Petal.Width)
