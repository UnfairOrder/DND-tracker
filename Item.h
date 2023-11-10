
/**
 * @brief An Item Interface
 * literally just defines the get weight method.
 */
class Item{
    public:
        virtual double get_weight()=0;
        virtual std::string get_name()=0;
        virtual std::string get_description()=0;

};