from collections import Counter

class FrequencyDistribution:
    def __init__(self, data):
        self.data = data
        self.frequency_table = None

    def compute_frequency(self):
        self.frequency_table = Counter(self.data)

    def print_frequency_table(self):
        if self.frequency_table is None:
            print("Frequency table is empty. Call compute_frequency() first.")
            return

        print("Element\tFrequency")
        for item, frequency in self.frequency_table.items():
            print(f"{item}\t{frequency}")

# Example usage:
data = [1, 2, 2, 3, 3, 3, 4, 4, 4, 4]
freq_dist = FrequencyDistribution(data)
freq_dist.compute_frequency()
freq_dist.print_frequency_table()
