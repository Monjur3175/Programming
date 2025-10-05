# Parameters
mu <- 5
sigma <- 2
n <- 30
N_sim <- 1000

# Initialize vectors
sample_vars <- numeric(N_sim)   # unbiased variances
biased_vars <- numeric(N_sim)   # biased variances

# Simulation for variance estimation
set.seed(123)
for (i in 1:N_sim) {
  data <- rnorm(n, mean = mu, sd = sigma)
  sample_vars[i] <- var(data)  # unbiased variance (denominator n-1)
  biased_vars[i] <- sum((data - mean(data))^2) / n  # biased variance (denominator n)
}

# Graphical Output for variance
par(mfrow = c(1, 2))
# Histogram of unbiased variances
hist(sample_vars, breaks = 30, col = "lightblue",
     main = "Unbiased Sample Variance", xlab = "Variance", border = "white")
abline(v = sigma^2, col = "red", lwd = 2)  # true variance line

# Histogram of biased variances
hist(biased_vars, breaks = 30, col = "lightgreen",
     main = "Biased Sample Variance", xlab = "Variance", border = "white")
abline(v = sigma^2, col = "red", lwd = 2)  # true variance line