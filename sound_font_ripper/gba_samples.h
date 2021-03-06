/*
 * Sound Font Samples class
 * 
 * This program is part of GBA SoundFont Ripper (c) 2012 by Bregalad
 * This is free and open source software.
 */

#ifndef GBA_SAMPLES_H
#define GBA_SAMPLES_H

#include "sf2.h"
#include <vector>

class GBASamples
{	// List of pointers to samples within the .gba file, position is # of sample in .sf2
	std::vector<uint32_t> samples_list;
	// Related sf2 class
	SF2 *sf2;

public:
	GBASamples(SF2 *sf2) : sf2(sf2)
	{}

	// Convert a normal sample to SoundFont format
	int32_t build_sample(uint32_t pointer);
	// Convert a Game Boy channel 3 sample to SoundFont format
	int32_t build_GB3_samples(uint32_t pointer);
	// Convert a Game Boy pulse (channels 1, 2) sample
	int32_t build_pulse_samples(uint32_t duty_cycle);
	// Convert a Game Boy noise (channel 4) sample
	int32_t build_noise_sample(bool metallic, int32_t key);
};

#endif
