void initial_conditions (std::vector<double> & mat);
void boundary_conditions (std::vector<double> & mat);
void relax_laplace (std::vector<double> & mat);
void print (const std::vector<double> & mat);
void print_gnuplot (const std::vector<double> & mat);
void start_gnuplot (void);
bool compare (const std::vector<double> & mat,const std::vector<double> & mat_tmp);
void test(std::vector<double> & mat);

