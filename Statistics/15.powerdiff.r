# Parameters
mu0 <- 5      # Null hypothesis mean
mu1 <- 6      # Alternative hypothesis mean
sigma <- 2    # Population standard deviation
n <- 30       # Sample size
alpha <- 0.05 # Significance level
N_sim <- 1000 # Number of simulations

# Initialize power counters
power_t_test <- 0
power_z_test <- 0

# Simulation
set.seed(123)
for (i in 1:N_sim) {
  # Simulate data under H1 (true mean = mu1)
  data <- rnorm(n, mean = mu1, sd = sigma)
  
  # Perform one-sample t-test
  t_test <- t.test(data, mu = mu0, alternative = "greater")
  if (t_test$p.value < alpha) {
    power_t_test <- power_t_test + 1
  }
  
  # Perform z-test
  z_stat <- (mean(data) - mu0) / (sigma / sqrt(n))
  z_critical <- qnorm(1 - alpha)
  if (z_stat > z_critical) {
    power_z_test <- power_z_test + 1
  }
}

# Calculate and print powers
power_t_test <- power_t_test / N_sim
power_z_test <- power_z_test / N_sim

print(paste("Power of t-test:", round(power_t_test, 4)))
print(paste("Power of z-test:", round(power_z_test, 4)))

# Graphical Output
par(mfrow = c(1, 2))

# --- 1. Power comparison between t-test and z-test ---
barplot(
  c(power_t_test, power_z_test),
  names.arg = c("t-test", "z-test"),
  col = c("lightblue", "lightgreen"),
  main = "Power Comparison",
  ylab = "Power",
  ylim = c(0, 1)
)

# --- 2. Effect of sample size on power (t-test) ---
sample_sizes <- seq(10, 100, by = 10)
power_t <- sapply(sample_sizes, function(n) {
  sum(replicate(
    N_sim,
    t.test(rnorm(n, mean = mu1, sd = sigma), mu = mu0, alternative = "greater")$p.value < alpha
  )) / N_sim
})

plot(
  sample_sizes, power_t, type = "b", pch = 19, col = "blue",
  main = "Power vs. Sample Size (t-test)",
  xlab = "Sample Size (n)",
  ylab = "Power",
  ylim = c(0, 1)
)
grid()
