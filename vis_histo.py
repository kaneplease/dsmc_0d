
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

def create_pics(datadir, picdir, num):
	x1 = pd.read_csv(datadir+str(num)+".csv", names=('x', 'y', 'z'))

	edges = np.linspace(-6,6,100)

	plt.ylabel("Velocity Distribution Function[]")
	plt.xlabel("Velocity[]")
	plt.ylim(0, 13000)
	plt.hist(x1['x'].values, bins = edges, alpha=0.5, label="Vx")

	plt.hist(x1['y'].values, bins = edges, alpha=0.5,label="Vy")

	plt.hist(x1['z'].values, bins = edges, alpha=0.5,label="Vz")
	# plt.savefig("Init_z.png")
	plt.legend()
	plt.savefig(picdir+str(num)+".png")
	plt.close()
	# plt.show()

def main():
	datadir = "cmake-build-debug/data/kn04/"
	picdir = "cmake-build-debug/pics/"
	for i in range(81):
		create_pics(datadir, picdir, i)

if __name__=='__main__':
	main()
