const unsigned int profileSize = 120;  
  
const double motionProfile[][2] = { 
{0.000232,  0.023177},
{0.001159,  0.046355},
{0.003245,  0.104298},
{0.006953,  0.185419},
{0.012748,  0.289717},
{0.021091,  0.417192},
{0.032448,  0.567845},
{0.047282,  0.741675},
{0.066055,  0.938683},
{0.089233,  1.158867},
{0.117277,  1.402229},
{0.150653,  1.668769},
{0.189822,  1.958486},
{0.23525, 2.27138},
{0.287399,  2.607451},
{0.346733,  2.9667},
{0.413716,  3.349127},
{0.488578,  3.743141},
{0.571322,  4.137156},
{0.661945,  4.531171},
{0.760449,  4.925186},
{0.866833,  5.319201},
{0.981097,  5.713216},
{1.103242,  6.107231},
{1.233267,  6.501246},
{1.371172,  6.895261},
{1.516957,  7.289276},
{1.670623,  7.68329},
{1.832169,  8.077305},
{2.001596,  8.47132},
{2.178902,  8.865335},
{2.364089,  9.25935},
{2.557157,  9.653365},
{2.758104,  10.04738},
{2.966932,  10.441395},
{3.18364, 10.83541},
{3.408229,  11.229424},
{3.640698,  11.623439},
{3.881047,  12.017454},
{4.129276,  12.411469},
{4.385386,  12.805484},
{4.649376,  13.199499},
{4.921246,  13.593514},
{5.200765,  13.97594},
{5.487469,  14.335189},
{5.780894,  14.67126},
{6.080577,  14.984155},
{6.386054,  15.273871},
{6.696863,  15.540411},
{7.012538,  15.783773},
{7.332617,  16.003958},
{7.656636,  16.200965},
{7.984132,  16.374795},
{8.314641,  16.525448},
{8.6477,  16.652924},
{8.982844,  16.757222},
{9.319611,  16.838342},
{9.657537,  16.896286},
{9.996158,  16.931052},
{10.334784, 16.931321},
{10.672726, 16.897095},
{11.00952,  16.839691},
{11.344702, 16.759109},
{11.677809, 16.65535},
{12.008377, 16.528414},
{12.335943, 16.378301},
{12.660044, 16.20501},
{12.980214, 16.008542},
{13.295992, 15.788896},
{13.606914, 15.546073},
{13.912515, 15.280073},
{14.212333, 14.990896},
{14.505904, 14.678541},
{14.792764, 14.343009},
{15.07245,  13.984299},
{15.344498, 13.602412},
{15.608672, 13.208667},
{15.864965, 12.814652},
{16.113378, 12.420637},
{16.35391,  12.026622},
{16.586562, 11.632607},
{16.811334, 11.238592},
{17.028226, 10.844577},
{17.237237, 10.450562},
{17.438368, 10.056548},
{17.631618, 9.662533},
{17.816989, 9.268518},
{17.994479, 8.874503},
{18.164089, 8.480488},
{18.325818, 8.086473},
{18.479667, 7.692458},
{18.625636, 7.298443},
{18.763725, 6.904428},
{18.893933, 6.510414},
{19.016261, 6.116399},
{19.130709, 5.722384},
{19.237276, 5.328369},
{19.335963, 4.934354},
{19.42677,  4.540339},
{19.509696, 4.146324},
{19.584742, 3.752309},
{19.651908, 3.358294},
{19.71142,  2.975599},
{19.763737, 2.61581},
{19.809321, 2.2792},
{19.848636, 1.965766},
{19.882146, 1.67551},
{19.910315, 1.408431},
{19.933605, 1.16453},
{19.952481, 0.943806},
{19.967407, 0.746259},
{19.978844, 0.57189},
{19.987258, 0.420698},
{19.993112, 0.292683},
{19.996869, 0.187846},
{19.998993, 0.106186},
{19.999947, 0.047703},
{20.000195, 0.012398},
{20.0002, 0.00027},
{20.0002, 0}};
