# Parameters
 mu0 <- 5  # Null hypothesis mean
 mu1 <- 6  # Alternative hypothesis mean
 sigma <- 2  # Population standard deviation
 n <- 30  # Sample size
 alpha <- 0.05  # Significance level
 N_sim <- 1000  # Number of simulations
 # Initialize counters
 type_I_errors <- 0
 type_II_errors <- 0
 # Simulation
 set.seed(123)
 for (i in 1:N_sim) {
 # Simulate data under H0
 data_H0 <- rnorm(n, mean = mu0, sd = sigma)
 t_test_H0 <- t.test(data_H0, mu = mu0, alternative = "greater")
 if (t_test_H0$p.value < alpha) {
 type_I_errors <- type_I_errors + 1
  }
 # Simulate data under H1
 data_H1 <- rnorm(n, mean = mu1, sd = sigma)
 t_test_H1 <- t.test(data_H1, mu = mu0, alternative = "greater")
 if (t_test_H1$p.value >= alpha) {
 type_II_errors <- type_II_errors + 1
  }
 }
 # Output
 print(paste("Type I Error Rate:", type_I_errors / N_sim))
 print(paste("Type II Error Rate:", type_II_errors / N_sim))
 print(paste("Power:", 1 - (type_II_errors / N_sim)))
 # Graphical Output
 par(mfrow = c(1, 2))
 # Type I Error Distribution
 hist(replicate(N_sim, t.test(rnorm(n, mean = mu0, sd = sigma), mu = mu0, alternative = "greater")$p.value),
 breaks = 30, col = "lightblue", main = "P-values under H0", xlab = "P-value", border = "white")
abline(v = alpha, col = "red", lwd = 2)
 # Type II Error Distribution
 hist(replicate(N_sim, t.test(rnorm(n, mean = mu1, sd = sigma), mu = mu0, alternative = "greater")$p.value),
 breaks = 30, col = "lightgreen", main = "P-values under H1", xlab = "P-value", border = "white")
 abline(v = alpha, col = "red", lwd = 2)