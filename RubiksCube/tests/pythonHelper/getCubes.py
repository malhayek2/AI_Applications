# Simple python application to spit out cube to init

def main():
	#fileName = input("Please enter the fileName: ")
	file=open("ColorCountCubes.txt","r")
	with open("ColorCountCubes.txt", "r") as fp:
		line = fp.readline()
		cnt = 1
		#create a newfile error if it exists
		f = open("output0.txt", "x")
		while line:
			print("Line {}: {}".format(cnt, line.strip()))
			line = fp.readline()
			f.write("init cube " + line)
			f.write("run Color.cmd\n")
			cnt += 1



main()