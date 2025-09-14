# Parameters
mu <- 5
sigma <- 2
n <- 30
N_sim <- 1000

# Initialize vectors
means <- numeric(N_sim)
medians <- numeric(N_sim)

# Simulation
set.seed(123)
for (i in 1:N_sim) {
  data <- rnorm(n, mean = mu, sd = sigma)
  means[i] <- mean(data)
  medians[i] <- median(data)
}

# Efficiency (ratio of variances)
efficiency <- var(medians) / var(means)
print(paste("Efficiency (Median/Mean):", efficiency))

# Graphical Output
par(mfrow = c(1, 2))

# Histogram of means
hist(means, breaks = 30, col = "lightblue", 
     main = "Distribution of Sample Means", 
     xlab = "Sample Means", border = "white")
abline(v = mu, col = "red", lwd = 2, lty = 2)   # true mean

# Histogram of medians
hist(medians, breaks = 30, col = "lightgreen", 
     main = "Distribution of Sample Medians", 
     xlab = "Sample Medians", border = "white")
abline(v = mu, col = "red", lwd = 2, lty = 2)   # true median
