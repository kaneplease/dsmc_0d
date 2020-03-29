import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import os


def compare_pics(datadir, picdir, num):
	x0 = pd.read_csv("/media/user/HDD/hattori/GP_deap/GP_for_0d_DSMC/data/csv_rawdata/2norm/"+str(num)+".csv", names=('x', 'y', 'z'))

	edges = np.linspace(-1050,1050,130)

	plt.ylabel("Velocity Distribution Function[]")
	plt.xlabel("Velocity[]")
	plt.hist(x0['x'].values, bins = edges, alpha=0.3, label="DSMC method Vx", color="b")
	plt.hist(x0['y'].values, bins = edges, alpha=0.3, label="DSMC method Vy", color='g')
	plt.hist(x0['z'].values, bins = edges, alpha=0.3, label="DSMC method Vz", color='r')

	x1 = pd.read_csv(datadir+str(num)+"_x.csv", names=('A','B'))
	y1 = pd.read_csv(datadir+str(num)+"_y.csv", names=('A','B'))
	z1 = pd.read_csv(datadir+str(num)+"_z.csv", names=('A','B'))

	plt.ylim(0, 1300000)
	#plt.plot(x1.A, x1.B, label='Inferred Vx', color="b")
	#plt.plot(y1.A, y1.B, label='Inferred Vy', color='g')
	#plt.plot(z1.A, z1.B, label='Inferred Vz', color='r')
	#plt.plot(x2.A, x2.B, label='Inferred ')
	plt.legend()
	plt.savefig(picdir+str(num)+".png")
	plt.close()
	# plt.show()

def compare_pics2(datadir, picdir, num):
	x0 = pd.read_csv(datadir+str(num)+".csv", names=('x', 'y', 'z'))
	edges = np.linspace(-2000,2000,130)

	plt.ylabel("Velocity Distribution Function[]")
	plt.xlabel("Velocity[]")
	plt.hist(x0['x'].values, bins = edges, alpha=0.2, label="DSMC method Vx", color='b')
	plt.hist(x0['y'].values, bins = edges, alpha=0.2, label="DSMC method Vy", color='g')
	plt.hist(x0['z'].values, bins = edges, alpha=0.2, label="DSMC method Vz", color='r')

	#plt.plot(x2.A, x2.B, label='Inferred ')
	plt.legend()
	plt.savefig(picdir+str(num)+".png")
	plt.close()
	# plt.show()

def main():
	current_dir = os.getcwd()
	datadir = current_dir + "/build/data/kn04/"
	picdir =  current_dir + "/build/data/pics/"
	for i in range(81):
		compare_pics2(datadir, picdir, i)
	#vis_mass(datadir, picdir)

if __name__=='__main__':
	main()
