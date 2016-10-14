#include "utility.h"

using namespace std;

SimMat sim_score[2];
SSimMat ssim_score[2];
vector<int> seed_set;
pthread_t threads[MAX_THREAD];
vector<int> initCount;

struct ThreadParams{
  int id;
  const SSimMat *sim_score;
  SSimMat *new_score;
};


static void InitBaseline();
static void InitRoleSim();
static void InitRoleSimPlus();
static void InitAlphaRoleSim();
static void InitRoleSimSeed();

static double MaxMatch(int x, int y, const SimMat &sim_score, const Graph &G1, const Graph &G2);
static double MaxMatchInit(int x, int y, const Graph &G1, const Graph &G2);
static double MaxMatchAlpha(int x, int y, const SSimMat &sim_score, const Graph &G1, const Graph &G2);

static void IterateBaseline(const SimMat &sim_score, SimMat &new_score);
static void IterateRoleSim(const SimMat &sim_score, SimMat &new_score);
static void IterateRoleSimPlus(const SimMat &sim_score, SimMat &new_score);
static void IterateAlphaRoleSim(const SSimMat &sim_score, SSimMat &new_score);
static void IterateRoleSimSeed(const SimMat &sim_score, SimMat &new_score);

// Calculate similarity matrix
void CalcSimilarity(algo_iter ai);
