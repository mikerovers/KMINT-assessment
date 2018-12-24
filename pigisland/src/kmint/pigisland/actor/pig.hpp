#ifndef KMINT_PIGISLAND_PIG_HPP
#define KMINT_PIGISLAND_PIG_HPP

#include <kmint/pigisland/domain/DNAString.h>
#include <kmint/pigisland/force/SteeringBehaviors.h>
#include <kmint/pigisland/force/EntityWithForce.h>
#include "kmint/play.hpp"
#include "boat.hpp"

namespace kmint
{
    namespace pigisland
    {
        class shark;

        class pig : public EntityWithForce
        {
        public:
            pig(math::vector2d location, boat &b, shark &s, std::vector<Obstacle> &obstacles);
            pig(math::vector2d location, boat &b, shark &s, std::unique_ptr<DNAString> dna, std::vector<Obstacle> &obstacles);

            bool perceptive() const override { return true; }
            scalar range_of_perception() const override { return 30.0f; };
            scalar radius() const override { return 8.0f; }
            bool incorporeal() const override { return false; }
            const ui::drawable &drawable() const override
            { return drawable_; }
            bool must_draw() const override { return !eaten && !saved; }
            void move(math::vector2d delta)
            { location(location() + delta); }
            void act(delta_time dt) override;
            void setEaten(bool e)
            { eaten = e; }
            bool isEaten() const;
            DNAString &getGeneticAttributes() const;
            boat &getBoat() const;
            shark &getShark() const;
            bool isSaved() const;
            void setSaved(bool saved);
            int getFitness() const;
            void setFitness(int fitness);
            void setGeneticAttributes(std::unique_ptr<DNAString> &gA);
            bool isDedicated() const;
            void setDedicated(bool dedicated);
        private:
            boat &boatActor;
            shark &sharkActor;
            play::image_drawable drawable_;
            std::unique_ptr<SteeringBehaviors> steeringBehaviors;
            std::unique_ptr<DNAString> geneticAttributes;

            bool eaten;
            bool saved;
            int fitness;
            bool dedicated;
        };

    } // namespace pigisland
} // namespace kmint

#endif /* KMINT_PIGISLAND_PIG_HPP */
